# UDP Unicast Receiver with Nanolog Logging

<h4> Use application directly with any setup</h4>
You can directly use the application without building it. Use files that are inside bin directory.<br>
i.e. <li> UDP_LISTENER </li> 
    <li> udp-listener.conf</li>
    <li> logs folder(if you want file logging inside logs folder)<li>.<br>
Modify udp-listener.conf according to your use.<br>I have added all about configuration below point number 3.

<br>

<h5> If want to build it then follow steps:</h5>
<h3>1. Environment Setup </h3><br />
Application is for Linux so would be covering environment setup for the same. <br/>

We just need the following to get started:
I have build config reader using boost. To build it you need to install boost library.

<li>C++ compiler (preferably g++) </li><br />
<li>Text-editor </li><br />
<li>cmake </li><br />
<li> boost.asio </li> <br />
If cmake is not installed in your linux system, Then install using following command:
```
sudo apt-get install cmake
```
<br>
The simplest way to get asio on linux is by executing the following command:<br />
```
sudo apt-get install libboost-all-dev  
```
<br>
If you’re using some other platform or the above doesn’t seem a good fit for you, follow the document [here](http://think-async.com/Asio/asio-1.10.6/doc/asio/using.html) to get asio on your system.

The next step is to make sure you have C++ compiler on your compiler. Either gcc or g++.
You can get the same with the following command in linux.

```
sudo apt-get install gcc 
```
or
```
sudo apt-get install g++ 
```

Once you have the compiler, you’re good to follow along. I am using visual studio code as a text editor. You can choose one of your choice.

<h3>2. How to build this application</h3>
I have added command in CMakeLists.txt to build cmake.
To build CMake in release mode run following command:
```
cmake -DCMAKE_BUILD_TYPE=Release
```
<br>DEBUG for dev debugging : 
```
cmake -DCMAKE_BUILD_TYPE=Debug
```

Note: While building CMake, You should in working directory where your CMakeLists.txt is.
Once you have successfully build cmake then a make file is generated. Now you have to run ``` make ``` command to compile your application.
<p> Application will be generated in bin directory as we have set in CMakeLists.txt.</p>

<h3>3. About Configuration</h3>
There should be a conf file where your application is. Config file name should be udp-listener.conf as we are accessing file using same name.
In config there are some fields I have added:
<ol>
<li>SERVER-IP=127.0.0.1 </li><br>
<li>SERVER-PORT=9090    </li><br>
<li>CONSOLE-LOGGING=true</li><br>
<li>FILE-LOGGING=false  </li><br>
<li>LOGS-LOCATION=./logs</li><br>
</ol>
1. SERVER-IP: IP of server from where you are trying to receive data.<br>
2. SERVER-PORT: PORT of server from where you are trying to receive data.<br>
3. CONSOLE-LOGGING: It should true if you want to see the receiving data on console, otherwise false.<br>
4. FILE-LOGGING: It should true if you want to write the receiving data in log file, otherwise false.<br>
5. LOGS-LOCATION: location of folder where you want to generate log file. Leave blank if you want in same directory where you application is. In the above example logs will be created inside logs folder.

