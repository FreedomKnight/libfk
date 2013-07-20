#include <fk.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct data {
    int dat;
} data;

data *new_data(int num) {
    data *ret_data = malloc(sizeof(data));
    memset(ret_data, 0, sizeof(data));
    ret_data->dat = num;
    return ret_data;
}
int main()
{
    List *list = new_list();
    
    list_push_front(list, new_data(5));
    list_push_front(list, new_data(6));
    list_push_front(list, new_data(7));
    list_push_front(list, new_data(8));
    list_push_front(list, new_data(9));
    list_insert(list, 1,new_data(1));
    list_delete(list, 3);

    assert(((data *) list_pop_front(list))->dat == 9);
    assert(((data *) list_pop_front(list))->dat == 1);
    assert(((data *) list_pop_front(list))->dat == 8);
    assert(list_has_cur(list)== true);
    assert(list_has_next(list)== true);
    assert(((data *) list_get_cur(list))->dat == 6);
    list_move_next(list);
    assert(((data *) list_get_cur(list))->dat == 5);
    assert(list_has_prev(list)== true);
    list_move_prev(list);
    assert(((data *) list_get_cur(list))->dat == 6);
    assert(list_size(list) == 2);

    delete_list(list);
    list = new_list();
    list_push_back(list, new_data(1));
    list_insert(list, 1, new_data(2));
    assert(((data*) list_get_back(list))->dat == 2);
    assert(((data*) list_get_cur(list))->dat == 1);
    assert(list_has_next(list) == true);
    assert(((data *)(list_get_next(list)))->dat == 2);
    assert(list_size(list) == 2);
    list_move_next(list);
    assert(((data*) list_get_cur(list))->dat == 2);
    list_delete(list, 1);
    assert(list_size(list) == 1);
    assert(((data*) list_get_cur(list))->dat == 1);
    list_delete(list, 1);
    assert(list_size(list) == 1);
    list_delete(list, 0);
    assert(list_size(list) == 0);

    delete_list(list);
    list = new_list();
    list_insert(list, 1, new_data(1));
    assert(list_has_cur(list) == false);
    list_insert(list, 0, new_data(1));
    assert(list_has_cur(list) == true);
    assert(((data *) list_get_front(list))->dat == 1);
    assert(((data *) list_get_back(list))->dat == 1);
    assert(((data *) list_get_cur(list))->dat == 1);
    list_delete(list, 0);
    assert(list_has_cur(list) == false);
    assert(list_has_next(list) == false);
    assert(list_has_prev(list) == false);
    assert(((data *) list_get_front(list)) == NULL);
    assert(((data *) list_get_back(list)) == NULL);

    delete_list(list);
    list = new_list();
    list_push_back(list, new_data(5));
    list_delete_cur(list);
    assert(list_get_cur(list) == NULL);

    list_push_back(list, new_data(7));
    list_push_back(list, new_data(6));
    assert(((data *)list_get_cur(list))->dat == 7);
    list_move_next(list);
    assert(((data *)list_get_cur(list))->dat == 6);
    list_delete_cur(list);
    assert(((data *)list_get_cur(list))->dat == 7);
    
    

    return 0;
}
    
