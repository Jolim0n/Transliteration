# Transliteration
Transliteration from English to Russian and from Russian to English

# Build with Visual Studio 17 and Build with CMake.

# How to launch
## If you have Linux:
You can simply run the CMakeLists.txt file through the command line.
[CMake for Windows and Linux](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

```
sudo apt-get install cmake
sudo apt-get install cmake-gui
cmake .
cmake --build .
```
## If you have Windows:
Open a command line.
Enter the path to the SMake folder where the project will be deployed.
### For example: 
```
cd C:\Users\User\source\repos\Transliteratio\Transliteratio\CMake
cmake .
cmake --build .
```
![example](https://user-images.githubusercontent.com/55711116/83637386-39c10680-a5b0-11ea-85a5-6bdce755fae4.PNG)

Project will build.

## To start a project you need:
Place the source files in the root folder of the project.
For instance:
### ![Снимок](https://user-images.githubusercontent.com/55711116/83633262-56a60b80-a5a9-11ea-82ac-b6957d309d72.PNG)

It is necessary to register the task file, which will contain information from which language you want to translate.
### For instance:
+ File conf.txt
+ code in.txt out.txt
+ decode in2.txt out2.txt

And after you can easy run this:
### ![example](https://user-images.githubusercontent.com/55711116/83634444-3ecf8700-a5ab-11ea-8c60-4eb1702362d0.PNG)

# Author
+ Made by: Kosinsky Denis.
+ [Linkedin](https://www.linkedin.com/in/denys-kosinskiy-025a391aa/)
