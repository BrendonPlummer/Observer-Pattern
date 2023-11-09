#include <iostream>
#include <vector>


class Subject
{
protected:
	std::vector<Observer*> myObservers;
	virtual bool ObserverExists(Observer* pObserver)
	{
		if (pObserver == nullptr) return false;

		for (int obsCount = 0; obsCount <= myObservers.size(); obsCount++)
		{
			if (myObservers[obsCount] == pObserver)
				return true;
		}
		return false;
	}
public:

	~Subject(void)
	{
		myObservers.clear();
	}
	virtual void RegisterObserver(Observer* pNewObserver)
	{
		pNewObserver->SetSubject(this);
		myObservers.push_back(pNewObserver);
	}
	virtual void RemoveObserver(Observer* pCurrentObserver)
	{
		for (int obsCount = 0; obsCount <= myObservers.size(); obsCount++)
		{
			if (myObservers[obsCount] == pCurrentObserver)
			{
				myObservers.erase(myObservers.begin() + obsCount);
				return;
			}
		}
	}
	virtual void NotifyObserver(void)
	{
		for (int obsCount = 0; obsCount <= myObservers.size(); obsCount++)
		{
			myObservers[obsCount]->Update();
		}
	}
};

class Observer
{
protected:
	Subject* pMySubject = nullptr;
public:
	virtual void SetSubject(Subject* pNewSubject)
	{
		this->pMySubject = pNewSubject;
	}
	virtual void RemoveSubject(void)
	{
		pMySubject->RemoveObserver(this);
		pMySubject = nullptr;
	}
	virtual void Update(void);
};

class WeatherDataServer : public Subject
{
private:
	float humidity = 0, temp = 0, pressure = 0;
public:
	float getTemperature(void) { return temp; }
	float getHumidity(void) { return humidity; }
	float getPressure(void) { return pressure; }

	void setWeatherValues(float newHum, float newTemp, float newPress)
	{
		humidity = newHum; temp = newTemp; pressure = newPress;
	}
};

class WeatherDataClient : public Observer
{
public:
	void Update(void)
	{
		WeatherDataServer* pWeatherData = (WeatherDataServer*)pMySubject;

		std::cout << "Humidity: " << pWeatherData->getHumidity() << "\tTemperature: " << pWeatherData->getTemperature() << "\tPressure: " << pWeatherData->getPressure() << std::endl;
	}
};

int main()
{
	WeatherDataServer* newWeatherStation = new WeatherDataServer;
	WeatherDataClient* newWeatherClient = new WeatherDataClient;

	newWeatherStation->RegisterObserver(newWeatherClient);
	newWeatherStation->NotifyObserver();
	newWeatherStation->setWeatherValues(20, 20, 20);
	newWeatherStation->NotifyObserver();

	newWeatherClient->RemoveSubject();

	newWeatherStation->NotifyObserver();

	delete newWeatherClient;
	delete newWeatherStation;

	return 0;
};




