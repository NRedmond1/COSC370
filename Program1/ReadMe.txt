ICMP Program Group Report

Lucas Martin, Nate Redmond, Antwan Pearson
Last Modified: 10 March 2019

Description:
  We were able our to successfully complete all tasks. First, we sent packets to our local host, 127.0.0.1, and successfully
  received output (see screenshots). Next, we pinged four different hosts on four different continents: www.sydney.edu.au in
  Australia, www.pku.edu.cn in China, www.google.com in North America, https://www.kyu.ac.ug/ in Africa, and www5.usp.br in
  South America. We used several references to further our understanding of the program and the algorithm. References and their
  purpose are below. In addition, our meeting times are listed below. One interesting thing we noticed while testing is that
  Asian servers do not seem to not respond to our ICMP pings, while North America, South America, Africa, and Australia servers do.
  We attempted to implement the extra credit examples but had trouble testing for “1: Destination Host Unreachable”

References
•	https://docs.python.org. Used to learn about functions such as select.select, htons, struct.pack, etc.cs. 
•	Textbook pages 161 to 180. Used to understand sockets.
•	Textbook website. Used for pseudo code to use as a reference/guide.
