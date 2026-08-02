class StockSpanner:

    def __init__(self):
        self.prices = []
        self.s = []
        self.day = 0

    def next(self, price: int) -> int:
        self.prices.append(price)
        while self.s and self.prices[self.s[-1]] <= price:
            self.s.pop()
        if not self.s:
            span = self.day+1
        else:
            span = self.day-self.s[-1]
        self.s.append(self.day)
        self.day += 1
        return span


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)