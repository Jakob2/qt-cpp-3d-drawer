#ifndef LOG_H
#define LOG_H

#include "QString"
#include "global.h"

class Log
{
public:
    Log();

protected:
    QString selPart;
    QString delPart;
    QString addPart;
    QString savPart;
    QString resPart;
    QString plusName;
    QString minusName;
    QString savColor;
};

#endif // LOG_H
