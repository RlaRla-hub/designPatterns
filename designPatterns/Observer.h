#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<memory>


class Observer
{
public:
	virtual void update(float temperature) = 0;
	virtual ~Observer() = default;
};

class Display : public Observer
{
public:
	void update(float temperature) override;
};

class Logger :public Observer
{
private:
	std::ofstream file;
public:
	Logger();
	void update(float temperature) override;
	~Logger();
};

class AlarmSystem : public Observer
{
public:
	void update(float temperature) override;
};

class WeatherStation
{
private:
	float currentTemperature = 0;
	std::vector<std::shared_ptr<Observer>> observers;

public:
	void setTemperature(float temperature);
	float getTemperature();
	void addObserver(std::shared_ptr<Observer> ob);
	void updateObservers(float temperature);
};
