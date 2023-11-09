#pragma once
#include <iostream>
#include <vector>

#include "Observer.h"

class Subject
{
protected:
	std::vector<Observer*> myObservers;
	virtual bool ObserverExists(Observer*);

public:

	~Subject(void);
	virtual void RegisterObserver(Observer*);
	virtual void RemoveObserver(Observer*);
	virtual void NotifyObserver(void);
};