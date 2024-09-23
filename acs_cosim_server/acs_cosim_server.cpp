#include <iostream>
#include <acs_cosim_protos/control_input.pb.h>

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    ControlInput in;
    in.set_steer(0.0);
    google::protobuf::ShutdownProtobufLibrary();
}