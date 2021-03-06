#include "wish_core.h"
#include "wish_identity.h"

#include "string.h"

int wish_core_update_identities(wish_core_t* core) {
    
    core->num_ids = wish_get_num_uid_entries();
    //printf("Number of identities in db: %i\n", num_ids);

    /* Load local user database (UID list) */
    memset(core->uid_list, 0, sizeof(core->uid_list));
    core->loaded_num_ids = wish_load_uid_list(core->uid_list, core->num_ids);
    
    //printf("Number of loaded identities: %i\n", core->loaded_num_ids);
    
    int i = 0;
    for (i = 0; i < core->num_ids; i++) {
        wish_identity_t id;
        memset(&id, 0, sizeof (wish_identity_t));
        return_t load_retval = wish_identity_load(core->uid_list[i].uid, &id);
        wish_identity_destroy(&id);
    }
    
    return 0;
}
