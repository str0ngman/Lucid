#ifndef EVENT_POST_COLLISION_ADD_H
#define EVENT_POST_COLLISION_ADD_H

#include "../Communication/IEventData.h"
#include <Box2D/Box2D.h>

class Event_PostCollisionAdd : public IEventData
{
private:
	b2Contact* m_Contact;
public:
	static const EventType s_EventType;
	Event_PostCollisionAdd(b2Contact* contact) : m_Contact(contact) { }

	const EventType& GetEventType() { return s_EventType; }
	std::shared_ptr<IEventData> Copy() const { return std::shared_ptr<IEventData>(new Event_PostCollisionAdd(m_Contact)); }
	const std::string GetName() const { return "Event_PostCollisionAdd"; }
	const b2Contact* GetContact() const { return m_Contact; }
};

#endif