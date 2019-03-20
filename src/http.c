#include <include/http.h>

void EcsHttpInit(EcsRows *rows) {
    EcsEntity *e = ecs_column(rows, EcsEntity, 0);

    int i;
    for (i = 0; i < rows->count; i ++) {
        ecs_add(rows->world, e[i], EcsContainer);
    }
}

void EcsComponentsHttp(
    EcsWorld *world,
    int flags,
    void *handles_out)
{
    EcsComponentsHttpHandles *handles = handles_out;

    ECS_COMPONENT(world, EcsHttpServer);
    ECS_COMPONENT(world, EcsHttpEndpoint);

    /* This system adds the EcsContainer component to entities with the
     * EcsHttpServer component. This lets application use the server as a
     * container for endpoints */
    ECS_SYSTEM(world, EcsHttpInit, EcsOnAdd, EcsHttpServer);

    ECS_SET_COMPONENT(handles, EcsHttpServer);
    ECS_SET_COMPONENT(handles, EcsHttpEndpoint);
}
