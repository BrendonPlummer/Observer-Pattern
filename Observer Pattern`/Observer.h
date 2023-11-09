#pragma once
#include <iostream>
#include "Subject.h"

class Observer
{
private:
	Subject* pMySubject = nullptr;

public:
	virtual void SetSubject(Subject*);
	virtual void RemoveSubject(void);
	virtual void Update(void);
};