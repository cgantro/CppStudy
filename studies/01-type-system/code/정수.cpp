#include <cstdint>


// using을 사용 시 강한 타입이 아니기에, 서로 반대로 넣어도 동작은 한다.
// 논리적으로 맞진 않다.
// using UserId = std::uint64_t; // type alias 
// using RoomId = std::uint64_t; // type alias 

// 강한 타입을 만들기 위해 struct로 래퍼를 만들어준다.
struct UserId {
    std::uint64_t value;
};

struct RoomId {
    std::uint64_t value;
};
void join_room(UserId user, RoomId room) {
    // ...
}

int main() {
    UserId alice = 1001;
    RoomId lobby = 2001;

    join_room(alice, lobby);
    join_room(lobby, alice); // 컴파일 에러 발생;
    // could not convert 'lobby' from 'RoomId' to 'UserId'
}