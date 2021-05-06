const fun=(data)=>{
	const tempData={...data};
	const requiredData=JSON.stringify(tempData);
	const ans=requiredData.replace(/,/g,'\n');
	console.log( ans);
}

const data={
	name:"Jay",
	deleted:true,
	assetType:"xnslnxsax"
}
fun(data);