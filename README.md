# twixt-game-cpro-pro-
twixt game in command line interface.

# Two main component of the game logic :  
1. the first logic is the line_check.In this we have to chech is the line that the player make between two points should not intersect.
   for this logic i have used an algorith that checks it condition (discussed with Masood Shahid(2025101075) ).

   logic is based on two conditions if those conditions are satisfied then the line will intersect.The conditions are as follows:
   
   1)the points should lie in the opposite side of the line(let  us take AB) with which we are checking the intersection.
   
   2)the mid point of the points must lie inside the rectange made by the line AB as diagonal.
the proof of this ligic is through exhaustion and it holds true for all knight moves.

Implementation:  
1.first find the point(let us call is p1) with which the currect dot(call it p2) will get connected.Then find the slope of the line(let it be s1).  
2.for each line in our line array we will find the slope of the line AB (let it be s2 ).  
3.If the product of slope s1 and s2 is positive then we can form a line between p1 and p2.  
4.If the  product is negative then we will check if the cordinates of mid point of p1 and p2 will line inside the rectangle made by line AB as diagonal. 







   


  
