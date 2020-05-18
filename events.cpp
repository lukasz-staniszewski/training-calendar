#include "events.h"
#include "event.h"

Events::Events()
{
}

void Events::add_event(Event ev)
{
    this->events.push_back(ev);
    std::sort(events.begin(), events.end(), comparePtrs);
}
