#include <iostream>
#include <cmath>

double function(double x){
    //This function implements the function in the picture (an arbitrary function)
    //<cmath> is included because it is a sine function.
    const double PI = 3.14159;
    return (sin(x + PI/4)); //return value simply follows the function given in the midterm question
}

double bisection(double lower, double upper){ //This recursive function "bisection" takes two values and finds a root (if it exists) between the two
    if(function(lower) * function(upper) > 0){ //If there is a valid root between two values, then sin(lower + PI/4) * sin(upper + PI/4) must be negative
                                               //If the product of the two function outputs is greater than zero, then no root lies between the two
        std::cout << "error" << std::endl;     //The proper error message is given and the function ends
        exit;
    }
    double middle = (upper + lower) / 2;       //middle is used in a recursive manner to narrow the range at which the root exists
                                               //as the function recursively calls, the range at which the root exists will be cut in half each time
    if (upper - lower < 0.001)                 //when the difference between upper and lower is 0.001 (the tolerance) both values are sufficiently close to the zero,
        return lower;                          //the function ends by returning the lower value
    else if (function(middle) * function(upper) > 0) //If the product of the function output of middle and upper is greater than zero, then the root lies between the lower and middle
        return bisection(lower, middle);             //The recursive call narrows the range from (lower,upper) to (lower,middle)
    else if (function(middle) * function(lower) > 0) //If the root lies within middle and lower
        return bisection(middle, upper);             //The recursive call narrows the range to (middle, upper)
}

int main() {    //From the given picture, we can see that there are two roots.
                //The Function bisection, which finds the roots must run once for each of the two roots
                //The two ranges that will be used is 4 to 7 and 7 to 10.
                //If we were to use invalid ranges, the error message would simply appear.
    std::cout << "First root is: " << bisection(4,7) << std::endl;      //Function finds and outputs the first root between 4 and 7
    std::cout << "Second root is: " << bisection(7,10) << std::endl;     //Function finds and outputs the second root between 7 and 10

    return 0;
}
