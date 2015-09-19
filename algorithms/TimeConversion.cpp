/* We only need to change the hours to convert the time from AM/PM format to 24 hour format. We need to add +12 to the hours if the time is in PM. We need to take care of 12:mm:ssAM types additionally as 12:mm:ssAM in 24 hour format is 00:mm:ss. 12:mm:ssPM type values in 24 hour format are of the form 12:mm:ss.
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int hh, mm, ss;
    char str[3];

    scanf("%d:%d:%d%2s", &hh, &mm, &ss, str);
    //printf("%02d:%02d:%02d%s\n", hh, mm, ss, str);

    if(hh == 12)
    	hh = 0;

    if(strcmp(str, "PM") == 0)
       hh += 12;

    printf("%02d:%02d:%02d\n", hh, mm, ss);

    return 0;
}
