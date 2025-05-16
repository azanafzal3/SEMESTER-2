#include"Feedback.h"
#include<string>
using namespace std;

char* Feedback::getReview()
{
    return review;
}

void Feedback::setReview(char* val)
{
    strcpy_s(review, 300, val);
}
