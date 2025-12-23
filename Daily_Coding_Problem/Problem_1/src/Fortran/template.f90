module dcp_1
implicit none
    private
    public is_sum

contains

function is_sum(v, k) result(res)
    integer, intent(in) :: v(:)
    integer, intent(in) :: k
    logical :: res
    res = .false.
end function is_sum

end module dcp_1
