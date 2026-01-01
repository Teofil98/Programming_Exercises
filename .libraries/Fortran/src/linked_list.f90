module linked_list
implicit none
private

type node_t
    integer :: data
    type(node_t), pointer :: next => null()
end type node_t

type linked_list_t
    type(node_t), pointer :: head => null()
end type linked_list_t

public :: linked_list_t
public :: linked_list_insert
public :: linked_list_print
public :: linked_list_remove

contains

subroutine linked_list_insert(list, data)
    type(linked_list_t), intent(inout) :: list
    integer, intent(in) :: data
    type(node_t), pointer :: new_node
    allocate(new_node)

    new_node%data = data
    new_node%next => list%head
    list%head => new_node
end subroutine linked_list_insert

subroutine linked_list_print(list)
    type(linked_list_t), intent(in) :: list
    type(node_t), pointer :: ptr

    write(*, fmt="(a)", advance="no") "["
    ptr => list%head
    do while(associated(ptr))
        write(*, fmt="(i0,a)", advance="no") ptr%data, ","
        ptr => ptr%next
    end do
    print *,"]"
end subroutine linked_list_print

subroutine linked_list_remove(list, data)
    type(linked_list_t), intent(inout) :: list
    integer, intent(in) :: data
    type(node_t), pointer :: prev, cur

    if(.not. associated(list%head)) then
        return
    end if

    prev => list%head
    cur => list%head
    if (list%head%data == data) then
        list%head => list%head%next
        deallocate(cur)
        return
    end if

    cur => list%head%next
    do while(associated(cur))
        if(cur%data == data) then
            exit
        end if
        prev => cur
        cur => cur%next
    end do

    if(associated(cur)) then
        prev%next => cur%next
        deallocate(cur)
    end if

end subroutine linked_list_remove

end module linked_list
