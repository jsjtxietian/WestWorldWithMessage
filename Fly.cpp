#include "Fly.h"

bool Fly::HandleMessage(const Telegram & msg)
{
	return m_pStateMachine->HandleMessage(msg);
}
