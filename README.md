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
+ Open a command line.
+ Enter the path to the СMake folder where the project will be deployed.
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

# Program development algorithm.
+ Check what is passed to the command line, if anything
+ If is equal to «/? »Withdraw help on the program.
+ If the second - read the name of the task file from the file.
+ Open the "task" file (If it does not open, display the error and close the program).
+ For each line from the file, execute:
   + Parse the line into three words: the second and third word - the names of input and output files.
   + If the first word is equal to "code" then execute algorithm 1.
   + If the first word is equal to "decode" then execute algorithm 2.
   + Otherwise output an error about the incorrect task file format.
+ Algorithm №1:
   + Opens input and output files (output error if failed).
   + For all read lines from the input file, transliterate the lines according to the algorithm №3, transliterate the line, write to the      source file and close the program.
+ Algorithm №2:
   + Opens input and output files (output error if failed).
   + For all read lines from the input file, transliterate the lines according to the algorithm №3, transliterate the line, write to the source file and close the program.
+ Algorithm № 3
   + On the input line in coding "code". At the output in the encoding "decode"
   + Pass the string to the class. We call f-tion for line transliteration.
   + Transliteration from Russian to English follows the algorithm: there are no exceptions, everything takes place in a loop, in the loop we look for the appropriate character in the line and replace it with a character from the line char rus [33] [10], which was done earlier.
   + Transliteration from English to Russian follows the algorithm: there is an exception, the exception is checked before the main loop, everything else goes in the loop, in the loop we look for the appropriate character in the line and replace it with a character from the line char eng [33] [10] earlier.

# Author
+ Made by: Kosinsky Denis.
+ [Linkedin](https://www.linkedin.com/in/denys-kosinskiy-025a391aa/)
