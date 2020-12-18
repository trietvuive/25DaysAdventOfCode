def neighbors(p):
    x,y,z,a = p
    for nx in range(x-1,x+2):
        for ny in range(y-1,y+2):
            for nz in range(z-1,z+2):
                for na in range(a-1,a+2):
                    if nx == x and ny == y and nz == z and na == a:
                        continue
                    yield (nx,ny,nz,na)
def main():
    matrix = []
    cin = "cin"
    while cin!= "":
        cin = input()
        matrix.append(cin)
    coords = set()
    for y in range(len(matrix)):
        for x in range(len(matrix[y])):
            if matrix[y][x] == '#':
                coords.add((x,y,0,0))
    for i in range(6):
        nextcoords = set()
        xl = [t[0] for t in coords]
        yl = [t[1] for t in coords]
        zl = [t[2] for t in coords]
        al = [t[3] for t in coords]
        for x in range(min(xl)-1, max(xl)+2):
            for y in range(min(yl)-1, max(yl)+2):
                for z in range(min(zl)-1, max(zl)+2):
                    for a in range(min(al)-1,max(al)+2):
                        active_n = 0
                        for n in neighbors((x,y,z,a)):
                            if n in coords:
                                active_n+=1
                        if (x,y,z,a) in coords:
                            if active_n == 2 or active_n == 3:
                                nextcoords.add((x,y,z,a))
                        elif active_n == 3:
                            nextcoords.add((x,y,z,a))
        coords = nextcoords
    print(len(coords))
            
    
main()