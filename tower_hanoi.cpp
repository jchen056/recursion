#include <iostream>
//using std::cin;
//using std::cout;
//using std::endl;
using namespace std;
#include <getopt.h> // to parse long arguments.
#include <cstdlib> // for atoi function

//A prototype might take three integers for the inputs, and then just print to cout.
void tower(int n, int start,int end,int mid){//n is number of disks

//base case: one disk and three pegs; moving disk from start peg  to end peg
if (n==1){
cout<<start<<" "<<end<<"\n";
return;}
tower(n-1,start,mid,end);
cout<<start<<" "<<end<<"\n";
tower(n-1,mid,end,start);
}


/* Here's a skeleton main function for processing the arguments. */
int main(int argc, char *argv[]) {
// define long options
static struct option long_opts[] = {
{"start",        required_argument, 0, 's'},
{"end",          required_argument, 0, 'e'},
{"num-disks",    required_argument, 0, 'n'},
{0,0,0,0} // this denotes the end of our options.
};
// now process the options:
char c; // to hold the option
int opt_index = 0;
short n=0,start=0,end=0; /* to store inputs to the towers function. */
while ((c = getopt_long(argc, argv, "s:e:n:", long_opts, &opt_index)) != -1) {
switch (c) {
case 's': // process option s
start = atoi(optarg);
break;
case 'e': // process option e
end = atoi(optarg);
break;
case 'n': // process option n
n = atoi(optarg);
break;
case '?': // this will catch unknown options.
// here is where you would yell at the user.
// although, getopt will already print an error message.
return 1;
}
}

/* TODO: now that you have the options and arguments,
* solve the puzzle. */

/*start takes values 1,2,3 and end takes values 1,2,3*/
int mid;
if (start==1 && end==3){
mid=2;}
else if(start==1 && end==2){
mid=3;}
else if(start==2 &&end==1){
mid=3;}
else if(start==2 && end==3){
mid=1;}
else if(start==3 &&end==1){
mid=2;}
else if(start==3 && end==2){
mid=1;}
else{
exit(-1);}
tower(n,start,end,mid);
return 0;
}