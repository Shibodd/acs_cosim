# acs_cosim_server
A server application to use Assetto Corsa as a co-simulation.

This application launches and patches Assetto Corsa in order to proceed to do the following:
- Wake up the Assetto Corsa physics driver thread for it to run a single physics step;
- Wait for the physics driver thread to finish the step;
- Retrieve the physics data from Assetto Corsa using its shared memory feature;
- Send this data to a remote application (e.g. Simulink);
- Wait for a control input (throttle, brake, steer...) from the remote application;
- Apply it to Assetto Corsa using VJoy;
- Repeat.

A Simulink S-Function will be published in a separate repository.
