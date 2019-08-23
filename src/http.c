#include <flecs_components_http.h>

void FlecsComponentsHttpImport(
    ecs_world_t *world,
    int flags)
{
    ECS_MODULE(world, FlecsComponentsHttp);

    ECS_COMPONENT(world, EcsHttpServer);
    ECS_COMPONENT(world, EcsHttpEndpoint);

    ECS_SET_COMPONENT(EcsHttpServer);
    ECS_SET_COMPONENT(EcsHttpEndpoint);
}
