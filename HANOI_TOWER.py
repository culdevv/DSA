
def hanoi_tower(n, from_peg = 'A', to_peg = 'B', aux_peg  = 'C', move = None):
    if move  == None:
        move = []
    if (n==0):
        return move
    else:
        hanoi_tower(n-1, from_peg, aux_peg, to_peg, move)
        move.append((from_peg, to_peg))
        hanoi_tower(n-1, to_peg, aux_peg, from_peg, move)
    return move

if __name__ == "__main__":
    n=5
    step = hanoi_tower(n)
    for i , (a,b) in enumerate(step, start = 1):
        print(f"Step {i} : {a} to {b}")
    print(f"Tong so buoc: {len(step)}")
    