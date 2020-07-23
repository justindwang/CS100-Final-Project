# CS 100 Programming Project

A. Justin Wang (jwang592@ucr.edu)
   Bernie Shan (bshan008@ucr.edu)
   
B.  Attendance System

C.  We plan to work on an app whose primary function is to track attendance. This app also has a secondary infraction documenting function, which is stored alongside attendance
    data on a local database.

D.  This app streamlines the attendance taking process and provides an easy way to store data. The most common method of tracking attendance is using spreadsheets, which can  
     become tedious and sometimes difficult to use. Our Attendance System allows for easy data input and storage through a simple and effective user interface, making taking 
     attendance easy and carefree.
     
E.  We plan to develop the app inside Visual Studios using the C++ language.

F.  The input of our project is the raw attendance/infraction data from the user. 
    The output of our project is the organization and storage of the inputted data inside a local database, which the user can access through an interface.


## How to Run Attendance Manager v.0.0.1 ##

<a href="https://github.com/bernieshan/CS100-Final-Project/archive/master.zip">Click here to download the application files</a> then run cmake and make on your computer to produce the application.exe file. From there, you can run Attendance Manager and begin tracking attendance and Attendance infractions. 


### Project Report ###

Attendance Manager uses a local database to store attendance data. Users can view the data using both the application and the database. The application is implemented using the Factory, Decorator, and Visitor Design Patterns. The application opens with a menu that has seven options, shown below.

<img width="500" alt="ss1" src="https://user-images.githubusercontent.com/67339503/88302091-47def980-ccba-11ea-8f1b-54ddcbec73be.PNG">

As you can see, there are methods to add and remove employees to and from the database, as well as the points associated with their attendance. The interface also has a display option that can display the point of an individual employee or the points of all the employees.

The Factory Pattern faciliates the creation of different Point objects that correspond to different Attendance infractions. 
The Decorator Pattern wraps the Employee class with a GoodEmployee class, which applies to employees that have no infractions.
The Visitor Pattern prints the attendance data of each Employee in an organized fashion.

### Sample input and output ###

Below you will find the output when we try to add "John Smith" with ID "001".

<img width="346" alt="ss2" src="https://user-images.githubusercontent.com/67339503/88303580-0b140200-ccbc-11ea-9388-618d2a58c4c3.PNG">

Next we will add an absence to the record. Notice the output.

<img width="461" alt="ss3" src="https://user-images.githubusercontent.com/67339503/88303994-88d80d80-ccbc-11ea-8bb4-306cc366e241.PNG">

Next we can view the detailed attendance information.

<img width="467" alt="ss4" src="https://user-images.githubusercontent.com/67339503/88304192-cdfc3f80-ccbc-11ea-82bb-a47bd869a4cb.PNG">

Finally, we can remove the infraction, in case there was an input mistake.

<img width="436" alt="ss5" src="https://user-images.githubusercontent.com/67339503/88304357-03089200-ccbd-11ea-9a66-fc691623fe3a.PNG">


Hopefully you enjoy our using our project!

