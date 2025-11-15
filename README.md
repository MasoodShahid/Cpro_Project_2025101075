# Cpro_Project_2025101075
twixt...cpro project...secA...2025101075(Masood Shahid)  
Instersection check logic (discussed with 2025101085(Udit Bajoriya))

Assume a line PQ connecting two ends of a horse move  
Any other line which connects the two ends of a horse move intersect this line if and only if the following conditions hold:  
1)both points are opposite with respect to the line PQ.  
2)the midpoint of the line must lie in the region bounded by the rectangle with PQ as diagonal and sides parallel to axis(including the edges)  
We proved this by exhaustively drawing all such lines which intersect it and verifying that the above two conditions always hold true.  
Implementation goes like this:  
For the equation of line PQ we find the slope m of the line and use (y-yp)=m(x-xp) where (xp,yp) is the coordinate of P.  
x1,y1 and x2,y2 are the two ends of line segment (horse move) of which we checking intersection with the existing line(PQ).  
m1= (y1-yp)-m(x1-xp)  
m2=(y2-yp)-m(x2-xp)  
now to check if x1,y1 and x2,y2 lie opposite with respect to PQ we just check if m1*m2<0 or not  
it is known that if m1*m2 <0 then it is opposite with respect to PQ.  
To check the midpoint lies in the region we can find mid point of the given line (x1+x2)/2,(y1+y2)/2 and check if min(x1,x2)  <=midptx<max(x1,x2) and similarly for y coordinate.  

