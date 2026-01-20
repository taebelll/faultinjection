Fault Injection Methods on Visual Studio Code (VS Code)
Silent Data Corruption (SDC) Fault, Crash Fault, Hang Fault, Benign Faults

This is a tutorial that shows how to inject faults into C programs in VS Code

1. Install VS Code on your computer. 
2. Download the Raspberry Pi Pico and CMake Tools Extensions in the Extensions Tab to the left of VS Code.
<img width="1919" height="1043" alt="Screenshot 2026-01-19 224059" src="https://github.com/user-attachments/assets/75c01565-a982-4ef0-9fc9-63183cbe69d3" />
<img width="1919" height="1028" alt="Screenshot 2026-01-19 224116" src="https://github.com/user-attachments/assets/bd3e00c6-d2b8-4e76-87c9-5804ee1e5ec1" />


In order to create a new Pico Project, you click on the Pico logo on the left, and you click on New C/C++ Project. From there, you will type the name of the program you are running and make sure to have "Pico" set as your Board Type and the box that says Console over USB.

Choose which code to start with, the Euler, Quicksort, or Matrix Multiplication.

Run the regular program first. In the sleep_ms section, you might have to adjust the delay time depending on how your Pico operates.

In order to run these programs, once you have the program loaded, first you have to save the program. 

Go to File -> Save in the top left. Then go to the Pico logo, and click on Compile Project. 

After, plug in the Raspberry Pi Pico to your computer and hold the BOOTSEL Button to it. Then, click on Run Project. After that, you will go over to the Serial Monitor, and go to the area where you have your COM ports located for your computer. 

Once that is selected, you can now click on the button that says "Start Monitoring". Your program will start to run. 6. Test each fault injection code program for the euler, quicksort, and matrix multiplication programs.

3. Choose which code to start with, the Euler, Quicksort, or Matrix Multiplication.

4. Run the regular program first. In the sleep_ms section, you might have to adjust the delay time depending on how your Pico operates.

5. In order to run these programs, once you have the program loaded, first you have to save the program. Go to File -> Save in the top left. Then go to the Pico logo, and click on Compile Project.
 
6. After, plug in the Raspberry Pi Pico to your computer and hold the BOOTSEL Button to it. Then, click on Run Project.

7.After that, you will go over to the Serial Monitor, and go to the area where you have your COM ports located for your computer. Once that is selected, you can now click on the button that says "Start Monitoring". Your program will start to run. 

8. Test each fault injection code program for the euler, quicksort, and matrix multiplication programs.
