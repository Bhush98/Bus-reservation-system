# Bus-reservation-system

	Bus Reservation System

Bus reservation system , involves ticket booking for pleasant and cherishable journeys . The challenge in this assignment is to build a great and fast system that can store user information , give admin rights to insert , delete and update information ,  help user to book tickets and give them great user-experience .
Implementing and creating such kind of system in “C”  was not an easy task as we know , C is used mainly for system programming , creating kernels , operating system , embedded system and much more .
Creating and maintaining a system that is data driven is a hefty job , and as we know, there is no database connectivity for “C” so we used file system as our database .
In this system , I implemented two entities one which is admin and the other one is the user , both having their own roles and responsibilities . Admin for performing CRUD operations on the system (i.e Creating , Reading , Updating and Deleting ) , and User to booking tickets and cancelling them  .

Scope for Admin : Can access both User and Admin .
Scope for User : Can only access User part of the system.

System Walkthrough : 

When the application is launched the screen displays two options for the user 
1 : Admin
2 : User

For user to login into Admin , the user should have valid credentials for the fields username and password .
For the user part it’s quite simple just select user from the options.
After the user is logged into the Admin part the user has the right to display , insert and delete the route details .
The user is given the following options :
 Enter Username : admin
 Enter Password: 


 <------Hello Admin------>

 What can I do for you from the following 


 1 : Route Details
 2 : Insert a New Route
 3 : Delete a Existing Route 



And for the user part the user is given the below options :
 1 : Book a Ticket
 2 : Cancel a Ticket 
 3 : View Current Booking Details 
 4 : Checkout & Exit
