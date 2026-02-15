#pragma once

#include <iostream>

class State
{
public:
	virtual void play() = 0;
	virtual void pause() = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual ~State() = default;
};

class StoppedState : public State
{
public:
	void play() override;
	void pause() override;
	void next() override;
	void previous() override;
};

class PlayingState : public State
{
public:
	void play() override;
	void pause() override;
	void next() override;
	void previous() override;
};

class PausedState : public State
{
public:
	void play() override;
	void pause() override;
	void next() override;
	void previous() override;
};

class AudioPlayer
{
private:
	std::unique_ptr<State> currentState;
public:
	
	AudioPlayer();

	void play();
	void pause();
	void next();
	void previous();
};

