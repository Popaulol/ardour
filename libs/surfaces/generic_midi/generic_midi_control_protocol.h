#ifndef ardour_generic_midi_control_protocol_h
#define ardour_generic_midi_control_protocol_h

#include <control_protocol/control_protocol.h>

namespace MIDI {
	class Port;
}

namespace ARDOUR {

class GenericMidiControlProtocol : public ControlProtocol {
  public:
	GenericMidiControlProtocol (Session&);
	virtual ~GenericMidiControlProtocol();

	int set_active (bool yn);
	static bool probe() { return true; }

	void set_port (MIDI::Port*);
	MIDI::Port* port () const { return _port; }

	void send_route_feedback (std::list<Route*>&);
	
  private:
	void route_feedback (ARDOUR::Route&, bool);
	MIDI::Port* _port;

	void port_change ();
};

}

#endif // ardour_generic_midi_control_protocol_h
