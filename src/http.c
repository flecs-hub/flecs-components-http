#include <include/http.h>

void EcsComponentsHttp(
    EcsWorld *world,
    int flags,
    void *handles_out)
{
    EcsComponentsHttpHandles *handles = handles_out;
    ECS_COMPONENT(world, EcsHttpServer);
    ECS_COMPONENT(world, EcsHttpEndpoint);

    handles->HttpServer = EcsHttpServer_h;
    handles->HttpEndpoint = EcsHttpEndpoint_h;
}
