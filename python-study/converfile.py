import os
import time


class TraversalFun():

    def __init__(self, rootDir, func=None, saveDir=""):
        self.rootDir = rootDir
        self.func = func
        self.saveDir = saveDir

    def TraversalDir(self):

        dirs, filename = os.path.split(self.rootDir)
        print('dirs:', dirs)
        print('filename=', filename)

        save_dir = ""
        if self.saveDir == "":
            save_dir = os.path.abspath(os.path.join(
                dirs, 'new_'+filename))
        else:
            save_dir = self.saveDir
        print('save_dir=', save_dir)

        if not os.path.exists(save_dir):
            os.makedirs(save_dir)
        print("save dir:", save_dir)

        TraversalFun.AllFiles(self, self.rootDir, save_dir)

    def AllFiles(self, rootDir, save_dir=''):

        for lists in os.listdir(rootDir):
            path = os.path.join(rootDir, lists)
            if os.path.isfile(path):
                # self.func(os.path.abspath(path),
                #           os.path.abspath(save_dir))
                print('original abspath:', os.path.abspath(path))

            if os.path.isdir(path):
                newpath = os.path.join(save_dir, lists)
                print('new abspath:', newpath)

                if not os.path.exists(newpath):
                    os.mkdir(newpath)

                TraversalFun.AllFiles(self, path, newpath)


if __name__ == '__main__':
    time_start = time.time()

    rootDir = os.path.abspath(
        r'/tmp/a')
    destDir = os.path.abspath(
        r'/tmp/b')

    tra = TraversalFun(rootDir, None, destDir)
    tra.TraversalDir()

    time_end = time.time()
    print('Totall cost:', (time_end-time_start)*1000, 'ms')
