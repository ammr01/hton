# Author
Author : Amr Al Asmer<br> 
Date : 8-Dec-2022<br>
<br>
# Purpose
Reverse bytes order for any data type ,so you don't need C hton specific type such as ( htons, htonl, etc ).<br >
<br> 
# Examples
int x = 0x0F000102;<br>
hton((void*) &x , sizeof(int));<br>
now x = 0x0201000F<br><br>
# Usage
hton(void* vptr , int size);<br><br>
#


