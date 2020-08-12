
aliroot -l -b <<EOF
gSystem->Load("/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/FlatTreeAna/AliSkimmedDataAnalysisMaker.so");
 AliSkimmedDataAnalysisMaker *ana=new AliSkimmedDataAnalysisMaker("test.root");
ana->bookHistogram();
ana->read_V0("/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/output/data/2018/LHC18r/296690/pass3/chunks_11/V0tree.root");
ana->WriteHistogram();
EOF
