import os
import time


class TraversalFun():
    def __init__(self, rootDir):
        self.rootDir = rootDir

    def TraversalDir(self):
        TraversalFun.AllFiles(self, self.rootDir)

    def AllFiles(self, rootDir):
        for lists in os.listdir(rootDir):
            path = os.path.join(rootDir, lists)
            if os.path.isfile(path):
                print('file:', os.path.abspath(path))
            elif os.path.isdir(path):
                TraversalFun.AllFiles(self, path)


if __name__ == '__main__':
    time1_start = time.time()

    rootDir = r"/tmp"
    tra = TraversalFun(rootDir)
    tra.TraversalDir()

    time2_end = time.time()
    print('totall cost:', (time2_end-time1_start), 's')
