#include "State.h"


void StoppedState::play()
{
	std::cout << "Start playback" << std::endl;
}
void StoppedState::pause()
{
	std::cout << "Music isn't on" << std::endl;
}
void StoppedState::next()
{
	std::cout << "Music isn't on" << std::endl;
}
void StoppedState::previous()
{
	std::cout << "Music isn'ton" << std::endl;
}


void PlayingState::play()
{
	std::cout << "Music has already played" << std::endl;
}
void PlayingState::pause()
{
	std::cout << "Music has just stopped" << std::endl;
}
void PlayingState::next()
{
	std::cout << "Start next song" << std::endl;
}
void PlayingState::previous()
{
	std::cout << "Start previous song" << std::endl;
}


void PausedState::play()
{
	std::cout << "Remove pause, start playback" << std::endl;
}
void PausedState::pause()
{
	std::cout << "Music has already stopped" << std::endl;
}
void PausedState::next()
{
	std::cout << "Music is stopped" << std::endl;
}
void PausedState::previous()
{
	std::cout << "Music is stopped" << std::endl;
}


AudioPlayer::AudioPlayer() : currentState(std::make_unique<StoppedState>()) {}

void AudioPlayer::play()
{
	currentState->play();

	if (dynamic_cast<PausedState*>(currentState.get()))
	{
		currentState.reset(new PlayingState());
	}
};
void AudioPlayer::pause()
{
	currentState->pause();
	if (dynamic_cast<PlayingState*>(currentState.get()))
	{
		currentState.reset(new PausedState());
	}
};
void AudioPlayer::next()
{
	currentState->next();
};
void AudioPlayer::previous()
{
	currentState->previous();
};
