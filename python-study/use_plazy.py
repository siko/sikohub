from importlib.resources import path
from pathlib import Path
import plazy
import sys

if __name__ == "__main__":
    path = sys.argv[1]
    files = plazy.list_files(root=path,
                             filter_func=lambda x: True if x.endswith(
                                 '.mdx') else False,
                             is_include_root=False)
    print(files)