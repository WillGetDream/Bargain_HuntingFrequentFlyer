# Bargain_HuntingFrequentFlyer


                                2014/2015 SOUTHERN CALIFORNIA REGIONAL
                                ACM INTERNATIONAL COLLEGIATE PROGRAMMING CONTEST
                                        Problem 6
                                        Bargain-Hunting Frequent Flyer
   After many years, Wing-and-a-Prayer Airlines has decided to revamp its frequent-flyer bonus plan.
Starting next year, they are going to switch from awarding miles based on flight distance to points based on
fares paid. While this makes sense for the airline, as they will now be rewarding the people who spend the
most, bargain hunters who made a habit of looking for extremely low fares that would earn many miles are
disappointed.
    One intrepid traveler wants to take maximum advantage of the existing program while he still can. He
spends time on the WP Airlines web site looking for the most round-about routings for both one-way and
round-trip travel that he can get for a given fare. However, the airline doesn’t post the miles that would be
earned for a given routing. He wants your team to write a program that will accept a routing as a series of
airports and determine the total great-circle distance that he would fly.
Input to your program will be in two parts. The first part is a list of up to 3,000 airports that WP
Airlines serves, one per line. Each line consists of the three-letter airport code, followed by four fields giving
the latitude (degrees, minutes, seconds, and the letter “N” for North or “S” for South) and four more fields
giving the longitude (degrees, minutes, seconds, and the letter “E” for East or “W” for West). Fields are
separated from each other by single spaces. Numeric values may contain leading zeroes. This list will end
with a line containing only three hyphens.
    The remainder of the input is a series of routings given as lists of airport codes, one per line. Each
routing is a series of airport codes separated by single spaces. The first airport code on the line is the point
of departure. The remaining airport codes are the points where our traveler will make a connection. The last
airport code on the line is the final destination (which might match the point of departure for a round-trip).
The last routing will be followed by the end-of-file.
For each routing, your program is to print the total great-circle distance, with the final total rounded
to the nearest integer. Treat the Earth as a sphere with a radius of 3958.75 miles.
No flight segment between two airports will be longer than 9,000 miles. No two airports will be at
exactly the same longitude. No individual routing will contain more than thirty airports.


Sample Input
MAD 40 28 20 N 03 33 39 W
CMN 33 22 04 N 07 35 16 W
RAK 31 36 24 N 08 02 10 W
JFK 40 38 23 N 73 46 44 W
HNL 21 18 57 N 157 55 36 W
NRT 35 45 53 N 140 23 11 E
YYZ 43 40 38 N 79 37 50 W
FRA 50 01 35 N 08 32 35 E
LAS 36 04 49 N 115 09 08 W
LAX 33 56 33 N 118 24 29 W
---
LAS LAX HNL LAX LAS
LAX YYZ FRA CMN
LAX MAD RAK



Problem 6
Bargain-Hunting Frequent Flyer (continued)
Output for the Sample Input
5578
7526
6494
