import queue


import queue
T, n = list(map(int, input().split()))
while T > 0:
    que = []
    for i in range(0, n):
        st = input()
        que.append(st.split())
    rSet = set()
    sSet = set()
    qPos = []
    waitQue = queue.Queue()
    for i in range(0, n):
        waitQue.put(i)
        qPos.append(0)
    while(not waitQue.empty()):
        tid = waitQue.get()
        pos = qPos[tid]
        if (pos >= len(que[tid])): continue
        act = que[tid][pos]
        if (act[0] == 'R'):
            useSet = sSet
            selfSet = rSet
        else:
            useSet = rSet
            selfSet = sSet
        to = int(act[1:])
        key = (to, tid)
        if key in useSet:
            useSet.remove(key)
            qPos[to] += 1
            qPos[tid] += 1
            waitQue.put(to)
            waitQue.put(tid)
        else:
            selfSet.add((tid, to))
    if (len(rSet) + len(sSet) > 0):
        print(1)
    else:
        print(0)
        
    T -= 1