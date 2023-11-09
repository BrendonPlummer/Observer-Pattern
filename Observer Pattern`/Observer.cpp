#include "Observer.h"

void Observer::SetSubject(Subject* pNewSubject)
{
	this->pMySubject = pNewSubject;
}
void Observer::RemoveSubject(void)
{
	pMySubject->RemoveObserver(this);
	pMySubject = nullptr;
}
void Observer::Update(void)
{

}