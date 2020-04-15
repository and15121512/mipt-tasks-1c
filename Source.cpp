#include <iostream>
#include <vector>
#include <memory>

constexpr size_t k_heap_count = 0;
constexpr size_t k_values_count = 9;

class State {
public:
    State(const std::vector<std::vector<char>> table) : table_(table) { }

    std::shared_ptr<State> CardMoveState(size_t from, size_t to);
    std::shared_ptr<State> DeletedGroupState(size_t from);
    bool Proccessing();

    bool CanBeMoved(size_t from, size_t to) const;
    bool HasHeapGroupToDelete(size_t heap) const;
    bool IsHeapEmpty(size_t heap) const;

    size_t CardNumber(size_t code) const;

private:
    std::vector<std::vector<char>> table_;
    std::vector<std::shared_ptr<State>> next_states_;
};

std::shared_ptr<State> State::CardMoveState(size_t from, size_t to) {
    std::shared_ptr<State> next = std::make_shared<State>(*this);
    next_states_.push_back(next);
    char to_move = next->table_[from].back();
    next->table_[to].push_back(to_move);
    next->table_[from].pop_back();
    return next;
}

std::shared_ptr<State> State::DeletedGroupState(size_t from) {
    std::shared_ptr<State> next = std::make_shared<State>(*this);
    next_states_.push_back(next);
    next->table_.erase(next->table_.end() - 9, next->table_.end());
    return next;
}

bool State::Proccessing() {
    size_t empty_count = 0;
    for (size_t heap = 0; heap < k_heap_count; ++heap) {
        if (IsHeapEmpty(heap)) {
            ++empty_count;
            continue;
        }
        if (HasHeapGroupToDelete(heap)) {
            DeletedGroupState(heap);
        }
        //...
    }
    return empty_count == k_heap_count;
}

bool State::CanBeMoved(size_t from, size_t to) const {

}

bool State::HasHeapGroupToDelete(size_t heap) const {
    if (table_[heap].size() < k_values_count) {
        return false;
    }
    size_t sorted_end = table_[heap].size() - 9;
    size_t prev = 0;
    for (; prev <= CardNumber(table_[heap][sorted_end]);
        prev = table_[heap][sorted_end], ++sorted_end);
    return sorted_end == table_[heap].size();
}

bool State::IsHeapEmpty(size_t heap) const {
    return table_[heap].empty();
}

size_t State::CardNumber(size_t code) const {
    // returns number of card(6, 7,..., 10, jack==11, queen==12, king==13, ace==14 ) according to the way
    // we encode each card
}

class Solitaire {
public:
    Solitaire(std::vector<std::vector<char>> start) : root_(State(start)) { }

    void BFS() {
        // ...
    }

private:
    State root_;
    
};

int main() {
    return 0;
}