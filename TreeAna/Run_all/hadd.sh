current_date=`date +"%Y_%m_%d"`

index=${1}

Dir_name="$current_date$index"

echo $Dir_name

mkdir -p ~/temp/$Dir_name

hadd -k  /u/xbai/temp/$Dir_name/splineQA_18q.root output/data/2018/LHC18q/*/pass3/*/hist.root
hadd -k  /u/xbai/temp/$Dir_name/splineQA_18r.root output/data/2018/LHC18r/*/pass3/*/hist.root
