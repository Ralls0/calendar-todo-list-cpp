#ifndef APIMAIN_H
#define APIMAIN_H
#include "../util/dateutil.h"
#include "../qlabel_event.h"



class APImain
{


public:
    explicit APImain();
    ~APImain();
    list<Event*> getEventByMonth(int month, int year);
};

#endif
