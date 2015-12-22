#ifndef MS_RTC_ROOM_H
#define MS_RTC_ROOM_H

#include "RTC/Peer.h"
#include "RTC/RTPPacket.h"
#include "RTC/RTCPPacket.h"
#include <unordered_map>
#include <json/json.h>

namespace RTC
{
	class Room : public RTC::Peer::Listener
	{
	public:
		static RTC::Room* Factory(Json::Value& data);

	public:
		Room();
		virtual ~Room();

		void Close();

	/* Pure virtual methods inherited from RTC::Peer::Listener. */
	public:
		virtual void onRTPPacket(RTC::Peer* peer, RTC::RTPPacket* packet) override;
		virtual void onRTCPPacket(RTC::Peer* peer, RTC::RTCPPacket* packet) override;

	private:
		// Others.
		typedef std::unordered_map<unsigned int, RTC::Peer*> Peers;
		Peers peers;
	};
}

#endif