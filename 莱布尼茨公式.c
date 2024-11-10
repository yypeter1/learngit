#include <jni.h>
#include <string>
#include <stdio.h>
#include <cmath>
using namespace std;
#define PI 3.1415926535
 
extern "C" JNIEXPORT jdouble JNICALL
Java_com_example_myapplication_JNI_1N_calculationPI(
        JNIEnv* env,
        jclass /* this */, jdouble precision) {
    double pi = 0.0;
    double term = 1.0;
    int sign = 1;
    while(fabs(pi*4-PI)> precision)
    {
        pi += sign * (1.0 / term);
        term += 2.0;
        sign *= -1;
    }
    return 4.0 * pi;
}
 
 