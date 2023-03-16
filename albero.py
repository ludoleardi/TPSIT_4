import random

class Node():
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

    def insertNode(self, key):
        #print("Inserimento")
        if self.key is None:
            self.key = Node(key)
        else:
            if key>self.key:
                if self.right is None:
                    self.right = Node(key)
                else:
                    self.right.insertNode(key)
                #print("destra")
            elif key<self.key:
                if self.left is None:
                    self.left = Node(key)
                else:
                    self.left.insertNode(key)
                #print("sinistra")

    def printTree(self, level=0):
        if self.left is not None:
            self.left.printTree(level+1)
        print(f"livello: ", level, " valore: ",self.key)
        if self.right is not None:
            self.right.printTree(level+1)
    
    def findNode(self, key):
        if key > self.key:
            if self.right == None:
                return f"nodo {key} non trovato"
            return self.right.findNode(key)
        elif key < self.key:
            if self.left == None:
                return f"nodo {key} non trovato"
            return self.left.findNode(key)
        else:
            return f"nodo {key} trovato"
        
    def height(self):
        if self.left is None:
            heightL = 0
        else:
            heightL = self.left.height()
        
        if self.right is None:
            heightR = 0
        else:
            heightR = self.right.height()
        
        if heightL > heightR:
            return heightL + 1
        else:
            return heightR + 1
          
def BuildBTree(nodes):
    """Nodes deve contenere valori ordinati crescenti"""
    l = len(nodes)
    if l == 0:
        return None
    m = l//2
    root = Node(nodes[m])
    root.left = BuildBTree(nodes[0:m])
    root.right = BuildBTree(nodes[m+1:])
    return root

def main():
    lista_key = list(range(0, 40, 5))
    random.shuffle(lista_key)
    print(lista_key)

    lista_key.sort()
    albero = BuildBTree(lista_key)

    albero.printTree() 
    
    print(albero.findNode(20))
    print(albero.height())

if __name__ == "__main__":
    main()