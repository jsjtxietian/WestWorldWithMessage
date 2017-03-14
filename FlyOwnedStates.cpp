#include "FlyOwnedStates.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "EntityNames.h"
#include "Time/CrudeTimer.h"
#include "Fly.h"

#include <iostream>


FLY * FLY::Instance()
{
	static FLY instance;
	return &instance;
}

void FLY::Enter(Fly * fly)
{
}

void FLY::Execute(Fly * fly)
{
	std::cout << "\nfuck flying now... wwwwww" << std::endl;

}

void FLY::Exit(Fly * fly)
{
}

bool FLY::OnMessage(Fly* fly, const Telegram & msg)
{
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_MinerCome:
	{
		std::cout << "\nMessage handled by " << GetNameOfEntity(fly->ID()) << " at time: "
			<< Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		std::cout << "\n" << GetNameOfEntity(fly->ID()) <<
			": aHA,somebody comes!";

		fly->GetFSM()->ChangeState(FIGHT::Instance());
	}

	return true;

	}//end switch

	return false;
}

FIGHT * FIGHT::Instance()
{
	static FIGHT instance;
	return &instance;
}

void FIGHT::Enter(Fly * fly)
{
	
}

void FIGHT::Execute(Fly * fly)
{
	std::cout << "\nFighting with miner  now... aaaaaaaaa" << std::endl;

}

void FIGHT::Exit(Fly * fly)
{

}

bool FIGHT::OnMessage(Fly * fly, const Telegram & msg)
{
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_MinerLeave:
	{
		std::cout << "\nMessage handled by " << GetNameOfEntity(fly->ID()) << " at time: "
			<< Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		std::cout << "\n" << GetNameOfEntity(fly->ID()) <<
			": aHA,that gay run away ";

		fly->GetFSM()->ChangeState(FLY::Instance());
	}

	return true;

	}//end switch

	return false;
}
