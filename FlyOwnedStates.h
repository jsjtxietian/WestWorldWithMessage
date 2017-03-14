#pragma once
#include "FSM\State.h"

class Fly;
struct Telegram;


class FLY :public State<Fly>
{
public:
	static FLY* Instance();

	virtual void Enter(Fly* fly);

	virtual void Execute(Fly* fly);

	virtual void Exit(Fly* fly);

	virtual bool OnMessage(Fly* agent, const Telegram& msg);

private:
	FLY() {};
	FLY(const FLY&);
	FLY& operator=(const FLY&);

};

class FIGHT : public State<Fly>
{
public:
	static FIGHT* Instance();

	virtual void Enter(Fly* fly);

	virtual void Execute(Fly* fly);

	virtual void Exit(Fly* fly);

	virtual bool OnMessage(Fly* agent, const Telegram& msg);
	
private:
	FIGHT() {};
	FIGHT(const FIGHT&);
	FIGHT& operator=(const FIGHT&);
};

