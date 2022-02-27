/** @author Sachin Saini
 *UDP receiver Application which receives unicast udp data and can log into file with the use of Nanolog logging library. 
 */
#include "src/UDP_LISTENER.h"
#include "src/logging/NanoLog.hpp"
#include <string>
#include <ctime>
#include "src/configReader.h"

void initializaLogging(std::string logDestination)
{
    //File Name: According to time, For unique everytime
    std::time_t t = time(NULL) + 19800;
    auto gmtime = std::gmtime(&t);

    char buffer[32];
    strftime(buffer, 32, "%Y%m%d-%T", gmtime);
    std::string t1(buffer);
    std::string fileName = "log-" + t1 + "_";
    std::cout << "FName: " << fileName << std::endl;
    //Till here we have just prepared a fileName, or instead of above code we can directly give file name
    if(logDestination!="")
    {
        logDestination +='/';
    }
    nanolog::initialize(nanolog::GuaranteedLogger(), logDestination, fileName, 200); //Initiallize Nanolog::GuaranteedLogger object with log file folder location and 200mb file size(A max of 200mb single file will contain after than new one is created) 

}
int main()
{
    UnicastReceiver udpUnicastReceiver;
    ConfigReader confReader;//Config reader class object
    std::string confFileName = "udp-listener.conf";
    std::string EMPTY_STRING ="";

    confReader.loadData(confFileName);    
    std::string serverIP = confReader.getValue<std::string>("SERVER-IP",EMPTY_STRING);
    int16_t serverPort   = confReader.getValue<int16_t>("SERVER-PORT",0);
    bool isConsoleLogging= confReader.getValue<bool>("CONSOLE-LOGGING",false);
    bool isFileLogging   = confReader.getValue<bool>("FILE-LOGGING",false);
    std::string logDestination = confReader.getValue<std::string>("LOGS-LOCATION", EMPTY_STRING);//second argument is default value, if there is nothing found in conf then default value will be used
    if(isFileLogging)
    {
        initializaLogging(logDestination);
        LOG_INFO << "*********************************************************";
        LOG_INFO << "UDP UNICAST Build Date: " << __DATE__ << "-" << __TIME__;
        LOG_INFO << "*********************************************************";

    }

    udpUnicastReceiver.initializerUDP(serverIP,serverPort,isConsoleLogging,isFileLogging);

    return 0;
}
