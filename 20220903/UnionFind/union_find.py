class union_find:
    __slots__ = ['_size', '_parent']
    def __init__ (self):
        self._size = 0
        self._parent = []

    def __init__ (self, n: int):
        self._size = n
        self._parent = [-1] * n

    def clear(self) -> None:
        self._size = 0
        self._parent.clear()

    def root(self, x: int) -> int:
        assert 0 <= x <= len(self._parent)
        if self._parent[x] < 0:
            return x
        else:
            self._parent[x] = self.root(self._parent[x])
            return self._parent[x]

    def size(self) -> int:
        return self._size

    def size(self, x) -> int:
        return -self._parent[x]
    
    def same(self, x: int, y: int) -> bool:
        return self.root(x) == self.root(y)
    
    def unite(self, x: int, y: int) -> bool:
        r_x, r_y = self.root(x), self.root(y)
        if r_x == r_y:
            return False
        if self._parent[r_x] > self._parent[r_y]:
            r_x, r_y = r_y, r_x
        self._parent[r_x] += self._parent[r_y]
        self._parent[r_y] = r_x
        self._size -= 1
        return True 

def main():
    n, q = map(int, input().split())
    uf = union_find(n)
    for i in range(q):
        p, a, b = map(int, input().split())
        if p == 0:
            uf.unite(a, b)
        else:
            if uf.same(a, b):
                print('Yes')
            else:
                print('No')

if __name__ == '__main__':
    main()