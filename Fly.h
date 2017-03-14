#pragma once
#include "BaseGameEntity.h"
#include "fsm/StateMachine.h"
#include "FlyOwnedStates.h"


template <class entity_type> class State; 

struct Telegram;

class Fly :public BaseGameEntity
{
public:
	Fly(int id ) :BaseGameEntity(id)
	{
		m_pStateMachine = new StateMachine<Fly>(this);
		m_pStateMachine->SetCurrentState(FLY::Instance());
	};

	~Fly() { delete m_pStateMachine; }

	bool HandleMessage(const Telegram& msg) ;

	StateMachine<Fly>* GetFSM()const { return m_pStateMachine; }


	void Update() 
	{

		m_pStateMachine->Update();
	}


private:
  StateMachine<Fly>* m_pStateMachine;

};

