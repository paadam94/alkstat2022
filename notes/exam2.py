import graphviz

if __name__ == "__main__":
    dot = graphviz.Digraph()

    # osszegek
    N = 8
    K = 5
    B = N-K
    # listak
    K = ["Tudja" + str(i) for i in range(1,K+1)]
    B = ["Bukja" + str(i) for i in range(1,B+1)]
    N = K + B
    # permutaciok
    import itertools

    p = list(itertools.permutations(N))
    for i in range(len(p)):
        p1 = p[i][0]
        p2 = p[i][1]
        dot.node(str(p1)+str(p2), \
                 str(i) + "{}-{}".format(p1, p2))
        

def exam1_solution():
    solve=lambda N,K : 1.0-(N-K)*(N-K-1)/(N*(N-1))
    n,k=[int(v) for v in input().split()]
    print(solve(n,k))
